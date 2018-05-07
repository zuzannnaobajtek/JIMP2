//
// Created by zuza on 07.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <regex>
#include <stdexcept>

namespace moviesubs {

    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out)=0;
        ~MovieSubtitles() = default;
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override ;

    };

    class SubtitlesExceptions : public std::invalid_argument {
    public:
        SubtitlesExceptions(int nrlinii, const std::string &linia);
        int LineAt() const;

    private:
        int inrlinii;
    };

    class NegativeFrameAfterShift : public SubtitlesExceptions {
    public:
        NegativeFrameAfterShift(int nrlinii, const std::string &linia);
    };

    class SubtitleEndBeforeStart : public SubtitlesExceptions {
    public:
        SubtitleEndBeforeStart(int nrlinii, const std::string &linia);
    };

    class InvalidSubtitleLineFormat : public SubtitlesExceptions {
    public:
        InvalidSubtitleLineFormat(int nrlinii, const std::string &linia);
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
