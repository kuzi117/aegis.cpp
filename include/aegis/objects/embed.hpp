//
// embed.hpp
// aegis.cpp
//
// Copyright (c) 2017 Sara W (sara at xandium dot net)
//
// This file is part of aegis.cpp .
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once


#include "../config.hpp"
#include "../snowflake.hpp"
#include "field.hpp"
#include "footer.hpp"
#include "image.hpp"
#include "thumbnail.hpp"
#include "video.hpp"
#include "provider.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>



namespace aegiscpp
{

/**\todo Needs documentation
*/
class embed
{
public:
    /// Adds a new embed field
    /**
     * @param name Name of the field
     * @param value Text to be shown within field
     * @param is_inline Sets whether the field is inline
     */
    void add_field(std::string name, std::string value, bool is_inline = false)
    {
        fields.emplace_back(name, value, is_inline);
    }
    /// Sets the title of the embed
    /**
    * @param str Title to set
    */
    void set_title(std::string str)
    {
        title = str;
    }
    /// Sets the description of the embed
    /**
    * @param str Description to set
    */
    void set_description(std::string str)
    {
        description = str;
    }
    /// Sets the url of the embed
    /**
    * @param str Url to set
    */
    void set_url(std::string str)
    {
        url = str;
    }
    /// Sets the timestamp of the embed
    /**
    * @param str Timestamp to set
    */
    void set_timestamp(std::string str)
    {
        timestamp = str;
    }
    /// Sets the color of the embed
    /**
    * @param clr Color to set
    */
    void set_color(int32_t clr)
    {
        color = clr;
    }
    // Combined Limit: 6000
    std::string title; /**<\todo Needs documentation */ // Limit: 256
    std::string type; /**<\todo Needs documentation */
    std::string description; /**<\todo Needs documentation */ // Limit: 2048
    std::string url; /**<\todo Needs documentation */
    std::string timestamp; /**<\todo Needs documentation */
    int32_t color = 0; /**<\todo Needs documentation */
    footer footer_; /**<\todo Needs documentation */ // Limit: 2048
    image image_; /**<\todo Needs documentation */
    thumbnail thumbnail_; /**<\todo Needs documentation */
    video video_; /**<\todo Needs documentation */
    provider provider_; /**<\todo Needs documentation */
    std::vector<field> fields; /**<\todo Needs documentation */ // Limit: 25 name:256 value:1024
};

/**\todo Needs documentation
*/
inline void from_json(const nlohmann::json& j, embed& m)
{
    if (j.count("title") && !j["title"].is_null())
        m.title = j["title"];
    if (j.count("type"))
        m.type = j["type"];
    if (j.count("description") && !j["description"].is_null())
        m.description = j["description"];
    if (j.count("url") && !j["url"].is_null())
        m.url = j["url"];
    if (j.count("timestamp") && !j["timestamp"].is_null())
        m.timestamp = j["timestamp"];
    if (j.count("color") && !j["color"].is_null())
        m.color = j["color"];
    if (j.count("footer") && !j["footer"].is_null())
        m.footer_ = j["footer"];
    if (j.count("image") && !j["image"].is_null())
        m.image_ = j["image"];
    if (j.count("thumbnail") && !j["thumbnail"].is_null())
        m.thumbnail_ = j["thumbnail"];
    if (j.count("video") && !j["video"].is_null())
        m.video_ = j["video"];
    if (j.count("provider") && !j["provider"].is_null())
        m.provider_ = j["provider"];
    if (j.count("fields") && !j["fields"].is_null())
        for (const auto& i : j["fields"])
            m.fields.push_back(i);
}

/**\todo Needs documentation
*/
inline void to_json(nlohmann::json& j, const embed& m)
{
    j["title"] = m.title;
    j["type"] = m.type;
    j["description"] = m.description;
    j["url"] = m.url;
    j["timestamp"] = m.timestamp;
    j["color"] = m.color;
    j["footer"] = m.footer_;
    j["image"] = m.image_;
    j["thumbnail"] = m.thumbnail_;
    j["video"] = m.video_;
    j["provider"] = m.provider_;
    for (auto i : m.fields)
        j["fields"].push_back(i);
}

}

