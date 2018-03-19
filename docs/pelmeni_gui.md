# Gui specifications
The gui should be cool and nice yes

## User scenarios
* Widgets are Nodes in the same way as entities and components. They exist in the SceneGraph, listen for events etc.
* A widget handler should handle all input and pass it down the widget tree.
* The Widget can contain a vector of unique pointers to widgets to enable widgets inside other widgets.
* A Widget should, if applicable, hold a raw pointer to a parent widget.
* A widget should support splitting for simultanous resizing of two adjacent widgets with the same depth.
* A widget is *interactive* if it listens for events. 