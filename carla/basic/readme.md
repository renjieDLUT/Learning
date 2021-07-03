## Client 和 World
```python
client = carla.Client('localhost', 2000)
client.set_timeout(2)
world = client.get_world()
weather = carla.WeatherParameters(cloudiness=10.0,\
                                  precipitation=10.0,\
                                  fog_density=10.0)
world.set_weather(weather)
```
## Actor 与 Blueprint

### 生成（spawn）Actor
```python
# 拿到这个世界所有物体的蓝图
blueprint_library = world.get_blueprint_library()
# 从浩瀚如海的蓝图中找到奔驰的蓝图
ego_vehicle_bp = blueprint.library.find('vehicle.mercedes-benz.coupe')
# 给我们的车加上特定的颜色
egp_vehicle_bp.set_attribute('color', '0,0,0')
# 找到所有可以作为初始点的位置并随机选择一个
transform = random.choice(world.get_map().get_spawn_points())
# 在这个位置生成汽车
ego_vehicle = world.spawn_actor(ego_vehicle_bp, transform)
```
### 操纵（Handing）Actor
```python
# 更改位置
location = ego_vehicle.get_location()
location.x += 10.0
ego_vehicle.set_location(location)
# 设置为自动驾驶模式
ego_vehicle.set_autopilot(True)
# 在中途将这辆车“冻住”，通过抹杀物理仿真
ego_vehicle.(False)
```
### 注销（Destory）Actor
```python
# 注销单个actor
ego_vehicle.destroy()
# 注销多个actor
client.apply_batch([carla.cammand.DestroyActor(x) for x in actor_list])
```
## sensor搭建
Sensor            |  输出数据形式   |功能        |类别
-------------------|  --------------------| -----------|-----------
RGB Camera  |  carla.Image    |  普通RGB相机  |Cameras
深度相机   |    carla.Image |  深度相机，以灰度图形式存储  |Cameras
分割相机   |  carla.Image | 直接输出景物分割图，不同颜色代表不同种类 | Cameras
collision    |  carla.CollisionEvent | 汽车发生碰撞时启动，会将事故的信息记录下来 | Detector
lane invasion | carla.LaneInvasionEvent | 汽车变道时启动，将Lane ID与汽车ID记录下来 |Detector
Obstacle   | carla.ObstacleDetect |将可能挡在前方形势道路上的物体记下 | Detector
Gnss    |  carla.GNSSMeasure | 记录车子的地理位置   | 
IMU   |  carla.IMUMeasurement|记录汽车的轴加速度和角加速度 |
Lidar  |  carla.LidarMeasurement | 激光雷达
radar  | carla.RadarMeasurement | 毫米波雷达
semantic Lidar | carla.SemanticLidarMeasurement| 除了3D点云外，还提供额外的Semantic信息 |

### Camera构建
```python
camera_bp = blueprint_library.find('sensor.camera.rbg')
camera_transform = carla.Transform( carla.Location(x = 1.5, z = 2.4) )
camera = world.spawn_actor(camera_bp, camera_transform, attach_to = ego_vehicle)
camera.listen(lambda image: image.save_to_disk(os.path.join(output_path, '%06d.png' % image.frame)))
```
### Lidar构建
```python
lidar_bp = blueprint_library.find('sensor.lidar.ray_cast')
lidar_bp.set_attribute('channels', str(32))
lidar_bp.set_attribute('points_per_second', str(90000))
lidar_bp.set_attribute('rotation_frequency', str(40))
lidar_bp.set_attribute('range', str(20))
# 安置激光雷达
lidar_location = carla.Location(0, 0, 2)
lidar_rotation = carla.Rotation(0, 0, 0)
lidar_transform = carla.Transform(lidar_location, lidar_rotation)
lidar = world.spawn_actor(lidar_bp, lidar_tranform, attach_to = ego_vehicle)
lidar.listen(lambda point_cloud:point_cloud.save_to_dist( \
				os.path.join(output_path, '%06d.ply' % point_cloud.frame)
```
##  观察者（spectator）放置
当我们去观察仿真界面时，我们会发现，自己的视野并不会随我们造的小车子移动，所以经常会跟丢它。解决这个问题的办法就是把spectator对准汽车，这样小汽车就永远在我们的视野里了！
```python
spectator = world.get_spectator()
transform = ego_vehicle.get_transform()
spectator.set_tranform(carla.Transform(transform.location + \ 	               						  carla.Location(z=20),\
 									  carla.Rotation(pitch=-90))

```

## 同步模式
time-stop 相当于仿真世界进行一次更新。两种：**variable time-step**和**fixed time-step**
**variable time-step**，仿真每次步长所需要的真实时间不一定；
```python
settings = world.get_settings()
settings.fixed_delta_seconds = None
world.apply_settings(settings)
```
**fixed time-step**，仿真每次步长所消耗的时间是固定的
```python
settings = world.get_settings()
settings.fixed_delta_seconds = 0.05
world.apply_settings(settiings)
```

```python
def sensor_callback(sensor_data, sensor_queue, sensor_name):
    if 'lidar' in sensor_name:
        sensor_data.save_to_disk(os.path.join('../outputs/output_synchronized', '%06d.ply' % sensor_data.frame))
    if 'camera' in sensor_name:
        sensor_data.save_to_disk(os.path.join('../outputs/output_synchronized', '%06d.png' % sensor_data.frame))
    sensor_queue.put((sensor_data.frame, sensor_name))

settings = world.get_settings()
settings.synchronous_mode = True
world.apply_settings(settings)

camera = world.spawn_actor(blueprint, transform)
sensor_queue = queue.Queue()
camera.listen(lambda image: sensor_callback(image, sensor_queue, "camera"))

while True:
    world.tick()
    data = sensor_queue.get(block=True)
```

#### traffic manager设置
```python
traffic_manager = client.get_trafficmanager(8000)
traffic_manager.set_synchronous_mode(True)

ego_vehicle = world.spawn_actor(ego_vehicle_bp, transform)
ego_vehicle.set_autopilot(True, 8000)
```

### client退出设置
```python
try:
  .......
finally:
  settings = world.get_settings()
  settings.synchronous_mode = False
  settings.fixed_delta_seconds = None
  world.apply_settings(settings)
```
## traffic manager(交通管理器)
用来控制车辆行为的模块。最大作用，帮用户群体管理一个车群。在同步模式下，设置AutoPilot的车辆必须依附于设置为同步模式的traffic manager才能跑起来。
### 内部架构
**第一阶段**：Vehicle Registry
**第二阶段**：Localization Stage
**第三阶段**：Collision Stage
**第四阶段**：Traffic Light State
**第五阶段**：Motion Planner
**第六阶段**：Send Command Array
[link]https://pic4.zhimg.com/80/v2-cb32de5de2cab0bfb48b0b9d2d71abd3_720w.jpg

### TM使用方法，创建TM
```python
world = client.get_world()
traffic_manager = client.get_trafficmanager(args.tm_port)
```
### traffic model设置
物理特性会考虑一些真实的物理限制，比如轮胎摩擦，道路曲率等。
设置模式**hybrid physics mode**开启后ego-vehicle附近一定范围内的车辆会开启物理特性，该模式就是为了减少计算消耗，只让ego-vehicle附近的交通更具有真实性。
### 车辆全局参数设置
tm默认所有的车辆限速为30公里每小时，通过设置global_percentage_speed_difference可以改变默认速度。80%意思是默认限速为24，-80%则意味着默认限速为30*180%=54km/h.
```python
# tm里的每一辆车都要和前车保持至少3m的距离来保持安全
traffic_manager.set_global_distance_to_leading_vehicle(3.0)
# tm里面的每一辆车都是混合物理模式
traffic_manager.set_hybrid_physics_mode(True)
# tm里面每一辆车都是默认速度的80%
traffic_manager.global_percentage_speed_difference(80)
```