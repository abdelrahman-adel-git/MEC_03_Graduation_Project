#ifndef AUTO_PARKING_H
#define AUTO_PARKING_H


void uninterrupted_delay_ms(const int interval);
void uninterrupted_center_the_wheels(void);

void search_for_left_vertical_parking_slot(void);
void search_for_left_angle_parking_slot(void);
void search_for_left_parallel_parking_slot(void);

void adjust_right_side_of_car(void);
void adjust_left_side_of_car(void);



#endif /*AUTO_PARKING_H*/