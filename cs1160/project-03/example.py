class Command:
    def run(self):
        raise NotImplementedError()

    def test_params(self):
        raise NotImplementedError()

class SuperCommand(Command):
    def run(self):
        print("It's a bird!")
        print("It's a plane!")
        print("It's Super Command!")

    def test_params(self):
        # No params to test, so we can just pass.
        pass


command = SuperCommand()
command.run()
