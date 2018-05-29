//
// Created by zuza on 21.05.18.
//

#include "Scheduler.h"

academia::SchedulingItem::SchedulingItem(int c_id, int t_id, int r_id, int t_slot, int yr) {
    course_id = c_id;
    teacher_id = t_id;
    room_id = r_id;
    time_slot = t_slot;
    year = yr;
}


int academia::SchedulingItem::CourseId() const {
    return course_id;
}

int academia::SchedulingItem::TeacherId() const {
    return teacher_id;
}

int academia::SchedulingItem::Year() const {
    return year;
}

int academia::SchedulingItem::RoomId() const {
    return room_id;
}

int academia::SchedulingItem::TimeSlot() const {
    return time_slot;
}

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule ret;
    std::copy_if(items_.begin(), items_.end(), std::back_inserter(ret.items_), [teacher_id](const SchedulingItem &it){ return it.TeacherId()==teacher_id;});
    return  ret;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule ret;
    std::copy_if(items_.begin(), items_.end(), std::back_inserter(ret.items_), [room_id](const SchedulingItem &it){ return it.RoomId()==room_id;});
    return  ret;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule ret;
    std::copy_if(items_.begin(), items_.end(), std::back_inserter(ret.items_), [year](const SchedulingItem &it){ return it.Year()==year;});
    return  ret;
}

std::size_t academia::Schedule::Size() const {
    return items_.size();
}

void academia::Schedule::InsertScheduleItem(academia::SchedulingItem item) {
    items_.emplace_back(item);
}

const academia::SchedulingItem &academia::Schedule::operator[](int n) const {
    return items_[n];
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector<int> n;
    std::vector<int> ret;

    for (auto &v: items_)
    {
        if (v.TimeSlot())
            n.push_back(v.TimeSlot());
    }

    for(int i = 1; i<=n_time_slots; i++)
        if(std::find(n.begin(), n.end(),i)==n.end())
            ret.push_back(i);

    return ret;
}
