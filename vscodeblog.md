### Using Cortex Debug for Nordic's nRF5x on Visual Studio Code

Here at Electronut Labs we work extensively on Bluetooth Low Energy technology. And, we have chosen Nordic semicondctor's nRF5x series boards for developing our products. We have our own range of breakout boards based on nRF5x series microcontrolers . You can visit out [website](https://electronut.in/portfolio/) or [tindie](https://www.tindie.com/stores/ElectronutLabs/) to purchase our boards. 

We really like Visual Studio Code editor for development. There UI is awesome and they provide some cool extension which will make your coding process fun and easy. I am going to talk about one such amazing extension for debugging *Cortex Debug* and several other extensions which will  will help you immensely in your development process.

**Cortex Debug** on Visual Studio Code is very fast and efficient. I will show you how to setup and start enjoying coding. This setup is going to work with any nRF5x development boards. And later I'm going to show you how to debug on our nRF5x breakout board [hackaBLE](https://electronut.in/portfolio/hackaBLE/) and programming using [Bumpy](https://electronut.in/portfolio/bumpy/), our SWD programmer.

## Setting up Cortex Debug configuration in VS Code

![Cortex Debug screen](https://github.com/electronut/electronut.github.io/blob/master/images/2018/07/cortex_debug.png)

Debugging ble_app_hrs example from nRF5 SDK. 

*Before setting up Cortex Debug you need to install the following*

1. [ARM GCC Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads) provides arm-none-eabi-gdb related tools.
2. [J-Link Software tools](https://www.segger.com/downloads/jlink) provides J-Link GDB server for J-Link based debggers.
3. Then you will need the following extensions.

    1. Install C/C++ Extension.
![c/c++ extension](https://github.com/electronut/electronut.github.io/blob/master/images/2018/07/cextension.png)

    2. Install Intellisense.
![intellisense](https://github.com/electronut/electronut.github.io/blob/master/images/2018/07/intellisense.png)

**Now you are ready to install Cortex Debug**

![cortex_debug](https://github.com/electronut/electronut.github.io/blob/master/images/2018/07/cortex_Debug.png)

Now, you are all set to debug your project. Go to Debug menu in Visual Studio code and select start debugging. you will see a small tab menu will appear, like this.

![debug_tab_menu](https://github.com/electronut/electronut.github.io/blob/master/images/2018/07/tab_debug_menu.png)

If you hover over the menu you will see it will allow you to step through, step into, step out, restart and stop the debugging. You also see three windows in the left for variable, stack and watch, this will keep track of all the variables currently present in the scope, the program stack.

![variable_stack](https://github.com/electronut/electronut.github.io/blob/master/images/2018/07/stack_variable.png)

As you can see it is very fast and easy to use.

## Debugging hackaBLE using Bumpy

I would like to briefly introduce our products hackaBLE and Bumpy before proceding further. 

[**hackaBLE**](https://electronut.in/portfolio/hackaBLE/) 

hackaBLE is a tiny (~ 18 mm x 28 mm) Open Source Nordic nRF52832 based BLE development board you can embed in your BLE projects.

[**Bumpy**](https://electronut.in/portfolio/bumpy/)

Bumpy is an inexpensive Open Source blackmagic probe compatible SWD debugger designed to be used with ARM GDB. It supports many platforms, but was primarily designed for use with our Nordic Semiconductor nRF BLE boards. 

[Here](https://github.com/electronut/ElectronutLabs-hackaBLE) is the full documentation about how to use hackaBLE and program it using [Bumpy](https://github.com/electronut/ElectronutLabs-Bumpy). 

**Setting up Cortex Debug congigurations for Bumpy**

Since Bumpy is blackmagic probe based SWD debugger you need to set its launch settings for that. Here what you need to write in launch.json file for configuring debugging in VS Code.

![Bumpy_settings](https://github.com/electronut/electronut.github.io/blob/master/images/2018/07/bmp_settings.png)

















