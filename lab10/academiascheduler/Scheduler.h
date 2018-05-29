//
// Created by zuza on 21.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <set>
#include <algorithm>

namespace academia {

    class SchedulingItem {
    public:
        SchedulingItem(int c_id, int t_id, int r_id, int t_slot, int yr);
        int CourseId() const ;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };

class Schedule {
public:
    void InsertScheduleItem(SchedulingItem item);
    Schedule OfTeacher(int teacher_id) const;
    Schedule OfRoom(int room_id) const;
    Schedule OfYear(int year) const;
    std::vector<int> AvailableTimeSlots(int n_time_slots) const;
    std::size_t Size() const;
    const SchedulingItem &operator[](int n) const;

private:
    std::vector<SchedulingItem> items_;
};

    class Scheduler {
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };


    class NoViableSolutionFound {

    };

    class GreedyScheduler : public Scheduler {

    };
};



#endif //JIMP_EXERCISES_SCHEDULER_H
