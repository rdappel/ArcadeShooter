# Arcade Shooter

![screenshot](https://cloud.githubusercontent.com/assets/5315168/25066698/7527f330-21f3-11e7-9914-e34baec6ecdd.png)

<br>

## Shooter Game for Arcade Cabinet

[![GitHub stars](https://img.shields.io/badge/build-passing-brightgreen.svg?style=flat-square)](https://github.com/RDAppel/ArcadeShooter)

<br>

## About the Project

[![GitHub issues](https://img.shields.io/github/issues/RDAppel/ArcadeShooter.svg?style=flat-square)](https://github.com/RDAppel/ArcadeShooter/issues)
[![GitHub issues](https://img.shields.io/github/issues-closed/RDAppel/ArcadeShooter.svg?style=flat-square)](https://github.com/RDAppel/ArcadeShooter/issues)

The Arcade Shooter is currently split into the four projects described below:

| **Project**             | **Description** | **Namespace API** |
| :---------------------: | :-------------- | :-------------: |
| **Katana Engine**       | Katana Engine is a library of classes, interfaces, and value types that provides a foundation for developing two-dimensional games in C++. | [Katana Engine API](http://ryan-appel.com/arcade_shooter/api/namespace_katana_engine.html) |
| **Shooter Library**     | Shooter Library is a library of classes, interfaces, and value types that provides a foundation for developing shoot 'em up style games. | [Shooter Library API](http://ryan-appel.com/arcade_shooter/api/namespace_shooter_library.html) |
| **Guardian Final Zero** | Guardian FZ it the main game that will be playable at launch. <br>_**Note:** Guardian FZ is not included in the documentation._ | N/A |
| **Sample**              | Sample is a sample game to use as a template for creating your own games utilizing the Katana Engine and Shooter Library. | [Sample API](http://ryan-appel.com/arcade_shooter/api/namespace_sample.html) |

<br>

## Getting Started

[![GitHub forks](https://img.shields.io/github/forks/RDAppel/ArcadeShooter.svg?style=flat-square)](https://github.com/RDAppel/ArcadeShooter/network)
[![GitHub stars](https://img.shields.io/github/stars/RDAppel/ArcadeShooter.svg?style=flat-square)](https://github.com/RDAppel/ArcadeShooter/stargazers)

To get started, fork this project to your Github account. Then setup your own project by following the steps below.

### Setup Tutorial:

<details> 
  <summary><span>Create your Game Project</span> (Click to Expand):</summary>

- Open up the _Arcade Shooter_ solution in Visual Studio.
- In the Solution Explorer you will see two folders; _Games_ and _Libraries_.

![solution_explorer](https://cloud.githubusercontent.com/assets/5315168/25034178/39c97f56-20aa-11e7-999b-941d5292624f.png)

- Right-click on the _Games_ folder, and select _Add > New Project..._
- Select _Visual C++_ (on the left) and select the _Empty Project_ type.
- Next, enter the name of your game, and click _OK_.

![add_new_project](https://cloud.githubusercontent.com/assets/5315168/25034192/4cd2146e-20aa-11e7-96f4-8c39f903d2f1.png)

You now have your own project! But, there's still some setup to do... Katana Engine is built upon a graphics library called Allegro.
Luckily, there is a NuGet package for it, so installation is pretty simple:

</details>
<br>
<details> 
  <summary><span>Install and Setup Allegro</span> (Click to Expand):</summary>

- In the Solution Explorer, right-click on _your project_, and select _Manage NuGet Packages_.
- Click _Browse_, and search for "allegro".

![nuget_allegro](https://cloud.githubusercontent.com/assets/5315168/25034427/f029ffd6-20ab-11e7-8654-0a1b12192d7e.png)

- Select the latest _Allegro 5_ package.
- Make sure that the Latest **Stable** version is selected, and click install. _You may have a "Review Changes" box pop-up. Just click OK_. 
- Right-click on _your project_ again (in the Solution Explorer), and select _properties_.
- Expand _Allegro 5_ (on the left) and select _Add-ons_, and then change all the _Addon_ values to "Yes."

![allegro_addons](https://cloud.githubusercontent.com/assets/5315168/25035140/58335c12-20b1-11e7-96c2-78369315f141.png)

- Click _OK_.

Okay, Allegro is all ready to go! Now, let's write a little code:

</details>
<br>
<details> 
  <summary><span>Create an entry point, and link to Katana Engine and Shooter Library</span> (Click to Expand):</summary>

- Within _your project_, locate the _Source Files_ folder.
- Right-click on it, and select _Add > New Item..._
- Name the file _Main.cpp_, and click _Add_.

![add_main](https://cloud.githubusercontent.com/assets/5315168/25035021/7aab0df4-20b0-11e7-8c6c-f28a56e1639f.png)

- Then type (or copy/paste) the following line:

```c++
int main() { return 0; }
```

- Now, let's build the solution. There are a number of ways to do this. I find _Ctrl + Shift + B_ to be the quickest.
- After building, we will now have an additional section in the project settings (Right-click on _your project_ and select _properties_).
- Notice, the _C/C++_ area? Click on _General_, and next to _Additional Include Directories_ add the following:

```
..\ShooterLibrary;..\KatanaEngine;
```

![additional_include](https://cloud.githubusercontent.com/assets/5315168/25035360/cbee30b8-20b2-11e7-8c03-06671d32a594.png)

- Click _OK_.
- Next, we need to add a couple of project references. Right-click on _your project_ and select _Add > Reference..._
- Check the checkboxes next to Katana Engine and Shooter Library.

![add_references](https://cloud.githubusercontent.com/assets/5315168/25036061/f8e4c704-20b6-11e7-9b5d-2248ea439763.png)

- Click _OK_.

Now you can incorporate all of the code from both of those projects! Last step in this tutorial:

</details>
<br>
<details> 
  <summary><span>Create and run Your Game class:</span> (Click to Expand):</summary>

- Add another item to _your project_ (Right-click, _Add > New Item..._).
- This time it needs to be a header file.

![add_game_header](https://cloud.githubusercontent.com/assets/5315168/25035669/8f0e212e-20b4-11e7-98bd-cbe4485f910e.png)

- Click _Add_.
- Copy and paste the following code:

```c++
#pragma once

#include "ShooterLibrary.h"				// Include the shooter library code!

class MyGame : public ShooterLibrary::Game		// "MyGame" inherits from the Shooter Game
{
public:

	virtual ~MyGame() { }

	virtual std::string GetName() const { return "My Game!!!"; }

};
```

- Switch over to Main.cpp and change the code to:

```c++
#include "MyGame.h"

int main() { return (new MyGame())->Run(); }
```

- To run your game, you'll need to set it as the "Startup Project." This can be found under the _Project_ Menu (_Project > Set as Startup Project_).
- Press _F5_ to Build and Run!

Okay, I admit it. It's not too exciting. However, your game is running, and (as proof) you can see the name in the title bar.

More tutorials to come! In the mean time, look at the Sample game code (found in the solution), and the documentation (found below).

</details>

<br>

## Documentation

[![Arcade Shooter Documentation](https://img.shields.io/badge/doxygen-4%2F15%2F17-003399.svg?style=flat-square)](http://ryan-appel.com/arcade_shooter/api/)

[Arcade Shooter Documentation](http://ryan-appel.com/arcade_shooter/api/)

<sub><sup>Documentation is generated using [Doxygen](http://www.stack.nl/~dimitri/doxygen/index.html).</sup></sub>

