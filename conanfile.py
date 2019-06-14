from conans import ConanFile, CMake


class ShaderEditor(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "imgui/1.69@bincrafters/stable",\
               "glfw/3.3@bincrafters/stable",\
               "glew/2.1.0@bincrafters/stable",\
               "opencv/4.1.0@conan/stable",\
               "Poco/1.9.0@pocoproject/stable"

    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
