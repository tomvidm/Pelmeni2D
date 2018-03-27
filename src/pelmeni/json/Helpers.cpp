#include "json/Helpers.hpp"

namespace p2d { namespace json {
    rapidjson::Document parseJsonFile(const std::string& filepath, const unsigned bufferSize) {
        FILE* file = fopen(filepath.c_str(), "r");
        if (file == NULL) {
            printf("Failed to open file %s\n", filepath.c_str());
            return rapidjson::Document();
        }
        char buffer[bufferSize];
        rapidjson::FileReadStream fReadStream(file, buffer, sizeof(buffer));

        rapidjson::Document doc;
        doc.ParseStream(fReadStream);
        fclose(file);

        return doc;
    }
} // namespace json
} // namespace p2d