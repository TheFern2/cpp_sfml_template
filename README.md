# cpp_sfml_template

A cross platform cmake template for sfml, with logging, and configuration.

## Using the template on Windows

The template is built for quick sfml projects, all you need is sfml installed.

I previously wrote guides for win/linux, follow sfml instructions, ignore the rest. jsoncpp, and spdlog are used as submodules on this repo. That one has some ready templates, but assumes you have jsoncpp, and spdlog built with cmake, it might not be optimal if you don't regularly work with sfml. If you do I encourage to do a system wide setup:

https://github.com/TheFern2/cpp_game_dev_templates/blob/main/docs/win/setup.md

```
git clone --recursive https://github.com/TheFern2/cpp_sfml_template.git
```

1. Launch cmake gui:

![](/images/project_1.PNG)

Point to root dir of repo for the source code. For the project, I make a build dir, it can be named anything.

2. Configure your desired project, I use vs2019 on x64.

![](/images/configure_2.PNG)

3. Hit configure, here the only thing you need to configure is SFML_DIR if you don't have a system env as per the setup documents, you can manually point to it.

![](/images/sfml_3.PNG)

Browse to your build project, and launch the solution or open project button from cmake gui.

4. Set cpp_sfml_template as startup project.
5. Go to project/properties/Linker/System change SubSystem to Console.
6. Run/debug you should see a simple green circle, and a log message.

![](/images/output.PNG)

# Using template on Linux

The process is always much easier on linux. :)

```
git clone https://github.com/TheFern2/cpp_sfml_template.git
```

Install libraries:
```
sudo apt-get install libsfml-dev
sudo apt-get install libjsoncpp-dev
sudo apt install libspdlog-dev
```

https://github.com/TheFern2/cpp_game_dev_templates/blob/main/docs/linux/setup.md

To build you can run `./install.sh`, to edit project use favorite editor, i.e. clion, vscode, etc.

# Using template on Mac

Tested with SFML 2.6.1 and Clion

```
git clone https://github.com/TheFern2/cpp_sfml_template.git
```

```
brew install spdlog
brew install jsoncpp
brew install sfml@2
```