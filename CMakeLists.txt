cmake_minimum_required(VERSION 3.1)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arduino-cmake/cmake/ArduinoToolchain.cmake)
project(blinky LANGUAGES C CXX)

set(ARDUINO_DEFAULT_PORT /dev/ttyACM0)
set(ARDUINO_DEFAULT_BOARD uno)

#### Uncomment below additional settings as needed.
set(${CMAKE_PROJECT_NAME}_SKETCH blinky.ino)
# set(mega.build.mcu atmega2560)
# set(mega.upload.protocol wiring)
# set(mega.upload.speed 115200)

generate_arduino_firmware(${CMAKE_PROJECT_NAME})

function(gen_example_category category)
    foreach(example IN LISTS ARGN)
        generate_arduino_example("${example}"
            CATEGORY "${category}"
            EXAMPLE "${example}")
        message(STATUS "${category}::${example}")
    endforeach()
endfunction()

################# BASICS #####################
gen_example_category(Basics
        blink
        analogreadserial
        bareminimum
        digitalreadserial
        fade
        readanalogvoltage)


################# DIGITAL #####################
gen_example_category(Digital
        blinkwithoutdelay
        button
        debounce
        digitalinputpullup
        statechangedetection
        tonekeyboard
        tonemelody
        tonemultiple
        tonepitchfollower)

################# Analog #####################
gen_example_category(Analog
        analoginoutserial
        analoginput
        analogwritemega
        calibration
        fading
        smoothing)

############### Communication #################
gen_example_category(Communication
        asciitable
        dimmer
        graph
        midi
        multiserial
        physicalpixel
        readasciistring
        serialcallresponse
        serialcallresponseascii
        serialevent
        serialpassthrough
        virtualcolormixer)

################## Control ####################
gen_example_category(Control
        arrays
        forloopiteration
        ifstatementconditional
        switchcase
        switchcase2
        whilestatementconditional)

################## Sensors ####################
gen_example_category(Sensors
        adxl3xx
        knock
        memsic2125
        ping)

################## Display ####################
gen_example_category(Display
        bargraph
        rowcolumnscanning)

################## Strings ####################
gen_example_category(Strings
        characteranalysis
        stringadditionoperator
        stringappendoperator
        stringcasechanges
        stringcharacters
        stringcomparisonoperators
        stringconstructors
        stringindexof
        stringlength
        stringlengthtrim
        stringreplace
        stringstartswithendswith
        stringsubstring
        stringtoint)

############ StarterKit_BasicKit #############
gen_example_category(StarterKit_BasicKit
        p02_spaceshipinterface
        p03_loveometer
        p04_colormixinglamp
        p05_servomoodindicator
        p06_lighttheremin
        p07_keyboard
        p08_digitalhourglass
        p09_motorizedpinwheel
        p10_zoetrope
        p11_crystalball
        p12_knocklock
        p13_touchsensorlamp
        p14_tweakthearduinologo
        p15_hackingbuttons)

############ ArduinoISP #############
gen_example_category(ArduinoISP
        arduinoisp)

#################### USB #####################
gen_example_category(USB
        keyboardandmousecontrol)

LIST(FIND ARDUINO_EXAMPLE_CATEGORIES usb USB_INDEX)
LIST(INSERT ARDUINO_EXAMPLE_CATEGORIES ${USB_INDEX} usb/mouse)
gen_example_category(USB/Mouse
        buttonmousecontrol
        joystickmousecontrol)

LIST(INSERT ARDUINO_EXAMPLE_CATEGORIES ${USB_INDEX} usb/keyboard)
gen_example_category(USB/Keyboard
        keyboardlogout
        keyboardmessage
        keyboardreprogram
        keyboardserial)

