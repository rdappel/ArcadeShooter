# Arcade Shooter
## Shooter Game for Arcade Cabinet

[![GitHub stars](https://img.shields.io/badge/build-passing-brightgreen.svg?style=flat-square)](https://github.com/RDAppel/ArcadeShooter)

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

## Documentation

[![Arcade Shooter Documentation](https://img.shields.io/badge/doxygen-4%2F14%2F17-003399.svg?style=flat-square)](http://ryan-appel.com/arcade_shooter/api/)

[Arcade Shooter Documentation](http://ryan-appel.com/arcade_shooter/api/)

<sub><sup>Documentation is generated using [Doxygen](http://www.stack.nl/~dimitri/doxygen/index.html).</sup></sub>

## Getting Started

[![GitHub forks](https://img.shields.io/github/forks/RDAppel/ArcadeShooter.svg?style=flat-square)](https://github.com/RDAppel/ArcadeShooter/network)
[![GitHub stars](https://img.shields.io/github/stars/RDAppel/ArcadeShooter.svg?style=flat-square)](https://github.com/RDAppel/ArcadeShooter/stargazers)

To get started, fork this project to your Github account. Then setup your own project by following the steps below.

### Seting up your Shooter Project:

**Create your Game Project:**

- Open up the _Arcade Shooter_ solution in Visual Studio.
- In the Solution Explorer you will see two folders; _Games_ and _Libraries_.

![solution_explorer](https://cloud.githubusercontent.com/assets/5315168/25034178/39c97f56-20aa-11e7-999b-941d5292624f.png)

- Right-click on the _Games_ folder, and select _Add > New Project..._
- Select _Visual C++_ (on the left) and select the _Empty Project_ type.
- Next, enter the name of your game, and click _OK_.

![add_new_project](https://cloud.githubusercontent.com/assets/5315168/25034192/4cd2146e-20aa-11e7-96f4-8c39f903d2f1.png)

You now have your own project! But, there's still some setup to do... Katana Engine is built upon a graphics library called Allegro.
Luckily, there is a NuGet package for it, so installation is pretty simple:

**Install and Setup Allegro:**

- In the Solution Explorer, right-click on _your project_, and select _Manage NuGet Packages_.
- Click _Browse_, and search for "allegro".

![nuget_allegro](https://cloud.githubusercontent.com/assets/5315168/25034427/f029ffd6-20ab-11e7-8654-0a1b12192d7e.png)

- Select the latest _Allegro 5_ package.
- Make sure that the Latest **Stable** version is selected, and click install. _You may have a "Review Changes" box pop-up. Just click OK._ 
- Right-click on _your project_ again (in the Solution Explorer), and select _properties_.
- Expand _Allegro 5_ (on the left) and select _Add-ons_, and then change all the _Addon_ values to "Yes."

![allegro_addons](https://cloud.githubusercontent.com/assets/5315168/25034732/41901656-20ae-11e7-90c9-c10eeb2653ef.png)

- Click _OK_.

Okay, Allegro is all ready to go! Now, let's write a little code:

**Creating an entry point:**

- Within _your project_, locate the _Source Files_ folder.
- Right-click on it, and select _Add > New Item..._
- Name the file _Main.cpp_, and click _Add_.

![add_main](https://cloud.githubusercontent.com/assets/5315168/25035021/7aab0df4-20b0-11e7-8c6c-f28a56e1639f.png)

- Then type (or copy/paste) the following line:

```c++
int main() { return 0; }
```





Last step:

####Setup your project to use Katana Engine and Shooter Library:

- 

