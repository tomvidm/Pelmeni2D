#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

namespace p2d { namespace json {
    rapidjson::Document parseJsonFile(const std::string& filepath, const unsigned bufferSize = 4096);
} // namespace json
} // namespace p2d