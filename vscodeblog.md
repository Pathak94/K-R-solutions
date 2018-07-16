### Debugging Nordic's nRF5x on Visual Studio Code

Here at Electronut Labs we work extensively on Bluetooth Low Energy technology. And, we have chosen Nordic semicondctor's nRF5x series boards for developing our products. We have our own range of breakout boards based on nRF5x series microcontrolers . You can visit out [website](https://electronut.in/portfolio/) or [tindie](https://www.tindie.com/stores/ElectronutLabs/) to purchase our boards. 

We really like Visual Studio Code editor for development. There UI is awesome and they provide some cool extension which will make your coding process fun and easy. I am going to talk about one such amazing extension for debugging *Cortex Debug* and several other extensions will help you immensely in your development process.

*Cortex Debug* on Visual Studio Code is very fast and efficient. I will show you how to setup and start enjoying coding. This setup is going to work with any nRF5x development boards. And later I'm going to show you how to debug on our nRF5x breakout board [hackaBLE](https://electronut.in/portfolio/hackaBLE/) and programming using [Bumpy](https://electronut.in/portfolio/bumpy/), our SWD programmer.

## Setting up Cortex Debug configuration in VS Code

![Cortex Debug screen](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")

Debugging ble_app_hrs example from nRF5 SDK. 

*Before setting up Cortex Debug you need to install the following*

1. [ARM GCC Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads) provides arm-none-eabi-gdb related tools.
2. [J-Link Software tools](https://www.segger.com/downloads/jlink) provides J-Link GDB server for J-Link based debggers.
3. Then you will need the following extensions.
   1. Install C/C++ Extension.
![c/c++ extension](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")
   2. Install Intellisense.
![intellisense](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")

*Now you are ready to install Cortex Debug*

![cortex_debug](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")








