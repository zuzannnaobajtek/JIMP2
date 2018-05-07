//
// Created by zuza on 07.05.18.
//

#include "MovieSubtitles.h"

using namespace moviesubs;

void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                            std::ostream *out) {
    if(frame_per_second <= 0)
        throw SubtitlesExceptions(frame_per_second, "dfgfg");

    int change = offset_in_micro_seconds*frame_per_second/1000;

    std::regex linia_regex(R"(\{(\d+)\}\{(\d+)\}(.+))");

    char buff[1000];
    int nrlinii=1;
    while(in->getline(buff, 1000)) {
        std::cmatch linia;

        if(std::regex_match(buff, linia, linia_regex)) {
            //INT_ON >= INT_OFF) należy zasygnalizować to wyjątkiem SubtitleEndBeforeStart
            int on = std::stoi(linia[1]) + change;
            int off = std::stoi(linia[2]) + change;
            if (on >= off)
                throw SubtitleEndBeforeStart(nrlinii, linia[3]);

            //in lub off < 0 NegativeFrameAfterShift
            if (on < 0 || off < 0)
                throw NegativeFrameAfterShift(nrlinii, linia[3]);

            (*out) << "{" << on << "}{" << off << "}" << linia[3] << "\n";

        }
        else
            //InvalidSubtitleLineFormat
            throw InvalidSubtitleLineFormat(nrlinii, linia[3]);

        nrlinii++;
    }

    //OutOfOrderFrames

}

SubtitlesExceptions::SubtitlesExceptions(int nrlinii, const std::string &linia) : invalid_argument("At line "+std::to_string(nrlinii)+": "+linia){
    inrlinii = nrlinii;
}

int SubtitlesExceptions::LineAt() const {
    return inrlinii;
}

NegativeFrameAfterShift::NegativeFrameAfterShift(int nrlinii, const std::string &linia) : SubtitlesExceptions(nrlinii,
                                                                                                              linia) {

}

SubtitleEndBeforeStart::SubtitleEndBeforeStart(int nrlinii, const std::string &linia) : SubtitlesExceptions(nrlinii,
                                                                                                            linia) {

}

InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(int nrlinii, const std::string &linia) : SubtitlesExceptions(
        nrlinii, linia) {

}
