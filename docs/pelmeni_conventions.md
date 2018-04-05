# Conventions
# Class conventions
If a class is used as a resource, it should have some aliases for types. In the snippet below, system::IdType is a type defined in the header `system/EngineDefs.hpp`

``` c++
class Resource {
    public:
        using id = system::IdType;
        using alias = std::string;
        using shared = std::shared_ptr<Resource>;
        using unique = std::unique_ptr<Resource>;
    // etc...
}
```