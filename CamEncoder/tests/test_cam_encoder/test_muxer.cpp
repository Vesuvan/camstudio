/**
 * Copyright(C) 2018  Steven Hoving
 *
 * This program is free software : you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see < https://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>
#include <CamEncoder/av_muxer.h>

av_video create_video(const av_video_meta &meta)
{
    av_video_codec video_codec_config;
    video_codec_config.id = AV_CODEC_ID_H264;

    return av_video(video_codec_config, meta);
}

TEST(test_muxer, test_create_muxer)
{
    av_video_meta meta;
    meta.bitrate = 4000;
    meta.bpp = 24;
    meta.height = 512;
    meta.width = 512;
    meta.fps = {25, 1};
    meta.preset = video::preset::ultrafast;  // configure 'almost' realtime video encoding
    meta.profile = video::profile::baseline; // lets try 264 baseline
    meta.tune = video::tune::zerolatency;
    auto video = create_video(meta);
    av_muxer muxer("test.mkv", av_muxer_type::mkv, false, meta, video);
}
