
class Missing:
    __instance = None

    def __init__(self):
        if Missing.__instance is not None:
            raise Exception("singleton class, call Missing.get_instance()")
        else:
            Missing.__instance = self

    @staticmethod
    def get_instance():
        if Missing.__instance is None:
            Missing()
        return Missing.__instance

    def equals(self, m):
        return self is m

