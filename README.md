<h1 align="center" id="title">Nice_UI</h1>

<p align="center"><img src="https://socialify.git.ci/vortexdevsoftware/Nice_ui/image?description=1&font=Source%20Code%20Pro&language=1&logo=https%3A%2F%2Fraw.githubusercontent.com%2Fvortexdevsoftware%2FNice_ui%2Fmain%2Fmedia%2Flogo_vector.png&name=1&owner=1&pattern=Solid&theme=Dark" alt="project-image"></p>

<p align="center" id="description">A feature-rich single header C++ interface system for <a href="https://www.glfw.org/">GLFW</a></p>
<p align="center"><img src="https://img.shields.io/github/license/vortexdevsoftware/Nice_ui?color=lightgrey&style=for-the-badge" alt="shields"> <img src="https://img.shields.io/github/stars/vortexdevsoftware/Nice_ui?style=for-the-badge" alt="shields"> <img src="https://img.shields.io/github/forks/vortexdevsoftware/Nice_ui?color=yellow&amp;style=for-the-badge" alt="shields"></p>

<h2 align="center">💡 Features</h2>

<p align="center">Here are some of the project's best features:</p>

*   📝 Simple to use without any hidden surprises and focused towards expected behavior.
*   🧱 Object-Oriented architecture; This means there is no need for creating the same element once every single frame just design the interface before the main loop and use Context->Render() to draw it.
*   🖥️ DPI Aware interface this means that when properly using screen-size based size values your elements should scale properly to many other resolutions.
*   📀 GLSL Shader support, if you require spicing-up your interface for your project.
*   🗔 Easily extensible framework. See <a href="plugins">Plugins</a>.

<h2 align="center">⌨️ Integrating it</h2>
To integrate it in your GLFW project, simply:
1. Put <a href="nice_ui.h">nice_ui.h</a> in your project's include folder.
2. Add #define NICE_UI_IMPLEMENTATION <b>before</b> using #include "nice_ui.h".
3. Create a context with New_Context().
See <a href="nice_ui_demo.cpp">nice_ui_demo.cpp</a> for a good example on how to use it.
