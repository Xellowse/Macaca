Macaca C. Module Template
===============================

INTRODUCTION
------------

Macaca C.(cyclopis) Module Template is a C language template of modulizing your code.
It include the feature of light weight,hardware compatible and cross-platform such
particularly suitable for the embedded system. Just fill up your code into this template,
and then your code will meet these feature and make your code BETTER.

DESCRIPTION
------------

There are some folder in this template.

1. Module :
    This folder is the main part of the module. You can put your main design into this part.

2. Module2 :
    This folder is the second module. This part is for demostration of interaction between
    modules. If your design need to seperated into 2 part, you can put your 2nd part into this
    folder.

3. HAL :
    This folder is for Hardware Abstraction Layer. HAL is the top layer of the module.
    If your code is hardware related.You should put the none hardware related part into
    HAL and design it as a virtualized hardware.

4. HW :
    This folder is for Hardware Layer. This layer is beneath HAL. Put your hardware control
    code here. If you expect there will be many generation's hardware to handle, you can
    seperate each generation's hardware control code of HW layer into sub folder HW_1, HW_2
    and so on. Make sure your HAL is well virtualized with the hardware then the HAL can link
    to each generation's HW layer easily.

5. IIF :
    This folder is for Integration Interface. Module should be independent between each
    other. If there are requirement of module's interaction,they should ineracted through
    IIF. You can put your control flow code of two module in IIF. IIF need to support single
    mode or dual mode let the module can operate independent. In single mode, IIF is work only
    with one module. In dual mode, IIF is work with both two module. This design is using different
    constructor to generate single mode or dual mode IIF. More detail, please refer to demo_iif.c

6. OSAL :
    This folder is for Operating System Abstraction Layer. The OS/platform related API call
    such like printf, printk, malloc,etc. Put thease APIs implementation in OSAL. Make your code
    outside of the OSAL folder is none OS/platform related.

7. ctor :
    Every part (HAL/HW/IIF/OSAL) have this folder. This folder is for constructor. Since
    this template is object(instance) based design. Every module's object(instance) is generated
    by constructor. Then the user can control the module through object(instance).

8. ut :
    Every part (HAL/HW/IIF/OSAL) have this folder. This folder is for Unit Test. You should
    test every API for your module to make sure your code is work correctly. In addition, You
    need to pack your ut code into a library let outside have the entry to do the global unit test.

9. UT :
    This folder is for whole system global unit test. It will call each parts(HAL/HW/IIF/OSAL) unit
    test lib to make sure every part is work correctly.

10. Document :
     There are some documents in this folder. You can find coding guide, ToDo List, etc. in
     this folder.

INSTALLATION
------------

Macaca is available both on linux user space and kernel space currently.

1. Whole System Build:
    You can build all part at onece. At the root path of Macaca:

    *Build for Linux user space:

        $make linux_u

    *Build for Linux kernel space:

        $make linux_k

    The *.ko/*.so of each part will all be generated in folder "out" in each folder.

2. Partial Build:
    You also can build each part independently. At the path of each folder:

    *Build for Linux user space:

        $make linux_u

    *Build for Linux kernel space:

        $make linux_k

    The *.ko/*.so of each part will be generated in folder "out" in each folder.


RUN DEMO
------------

   The demo code is put at Macaca/demo. In this folder:

    *Run for Linux user space:

        $make linux_u
        $cd out
        $./demo
        $./demo_iif
        $./demo_iif_single

    *Run for Linux kernel space:

        $make linux_k
        $./quit.sh
        $./go.sh   or  $./go_single.sh

        You can see some action log by

            $dmesg

        To close the demo

            $./quit.sh

RUN UNIT TEST
---------------

   You should test your implementation by unit test to ensure your code is work
   correctly. Unit test is built by whole system build automatically. Otherwise,
   you can also use partial build and run the unit test.

   You can run whole systemunit test by following step:

   At Unit Test folder Macaca/UT:

   *Run Unit Test for Linux user space:

       $make linux_u
       $cd out
       $./ut_all

   *Run Unit Test for Linux kernel space:

       $make linux_k
       $./quit.sh
       $./go.sh

       You can see the unit test result by

           $dmesg

       To close the unit test

           $./quit.sh

VERSIONING
----------
This project is following the sematic versioning. In addition,there are some
extra versioning rule. For more detail, please refer to
Document/coding_guide.txt

For each version's update note, please refer to file VERSION.

Version is embedded in the binary. You can get each binary's version by command.
For example:

  $cat libiif.so -a | grep "sv#"



LICENSE
--------
This project is under the MIT license. More detail please refer to LICENSE.


CONTRIBUTING
------------
This project is keeping develop. You can refer to Document/todo.txt for
more future work information. If you are interest for contributing or you
have any idea, welcome to contact me by e-mail first.
e-mail : weicheng.s3lab@gmail.com
