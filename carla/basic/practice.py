import carla


def main():
    client = carla.Client("localhost", 2000)
    client.set_timeout(2.0)

    world = client.get_world()
    print(world.get_map().name)
    print(client.get_available_maps())


if __name__ == "__main__":
    main()
