#include <string>

namespace p2d { namespace system {
    class Blueprint {
    public:
        using id = std::string;
        Blueprint(const Blueprint::id& bpid)
        : blueprintId(bpid) {;}

        inline id getId() const { return blueprintId; }
    private:
        id blueprintId;
    }; // class Blueprint
} // namespace system
} // namespace p2d