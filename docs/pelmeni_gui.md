# Gui specifications
The gui should be cool and nice yes

## User scenarios
* A widget handler should handle all input and pass it down the widget tree.
* The Widget can contain a vector of unique pointers to widgets to enable widgets inside other widgets.
* A Widget should, if applicable, hold a raw pointer to a parent widget.
* A widget should support splitting for simultanous resizing of two adjacent widgets with the same depth.