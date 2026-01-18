#include "converter_factory.h"
#include "converter.h"
#include "converter_mix.h"
#include "converter_mute.h"
#include "converter_loudly.h"
#include <memory>
#include <unordered_map>
#include <functional>
#include <stdexcept>

ConverterFactory::ConverterFactory() {
    register_converters();
}

void ConverterFactory::register_converters() {
    creators["mute"] = []() { return std::make_unique<MuteConverter>(); };
    creators["mix"] = []() { return std::make_unique<MixConverter>(); };
    creators["volume"] = []() { return std::make_unique<VolumeConverter>(); };
}

ConverterPtr ConverterFactory::create(const std::string &name) const {
    auto it = creators.find(name);
    if (it == creators.end()) {
        throw std::invalid_argument("Unknown converter: " + name);
    }
    return it->second();
}
std::vector<std::string> ConverterFactory::get_available_converters() const {
    std::vector<std::string> result;
    for (const auto &pair: creators) {
        result.push_back(pair.first);
    }
    return result;
}
