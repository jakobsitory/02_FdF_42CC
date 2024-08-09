# FdF
The **FdF** project is a challenge within the 42 School curriculum aimed at deepening students' understanding of computer graphics, 3D projections, and algorithmic design in C. The goal is to create a 3D wireframe model representation of a landscape from a file containing height maps, and to display this model in a window using the MinilibX library.

## **Task**

The task was to implement a program that reads a file containing a map of heights and creates a 3D representation of this data using a wireframe model. The program needs to handle various tasks such as:

- Parsing a file containing a grid of heights and storing this data in a structured format.
- Implementing a 3D projection algorithm to visualize the height map as a wireframe model.
- (Bonus) Handling user inputs for interactions like rotating, scaling, and translating the model.

**Key objectives included:**
- Designing and implementing an algorithm to accurately project 3D coordinates onto a 2D plane using isometric projection.
- Ensuring that the program handles large maps efficiently, displaying them with smooth performance.
- (Bonus) Enhancing the user experience with additional features such as dynamic color changes, alternate projection modes, and more interactive controls.

## **Key Achievements**
- Advanced 3D Projection Implementation: Successfully implemented the isometric projection algorithm and additional projection modes, allowing for an accurate and visually appealing 3D wireframe model.
- Enhanced User Interactivity (Bonus)
- Optimized Parsing and Rendering: Efficiently parsed large height maps and optimized the rendering process, ensuring smooth performance even with complex and detailed maps.

## Installation

To install the Project, follow these steps:
1. Clone the repository: **`git clone git@github.com:jakobsitory/02_FdF_42CC.git`**
2. Navigate to the project directory: **`cd FdF`**
4. Build the project: **`make`**

## **Usage**
1. Run the program with a map file: **`./fdf [map_file]`** (map files can be found in the **`tests`** directory)
2. Use keyboard input to interact with the model:


| **Key**           | **Function**                                      |
|-------------------|---------------------------------------------------|
| **Arrow Keys**    | Rotate the Model                                  |
| **I**             | Switch between isometric and parallel projection  |
| **+** / **-**     | Zoom in and out of the model                      |
| **4** / **8** / **6** / **2** [numpad] | Translate the model          |
| **5** [numpad]    | Center model in window                            |
| **Esc**           | Close the window                                  |



