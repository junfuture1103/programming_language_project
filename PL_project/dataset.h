#pragma once
class dataset
{

public:
    unsigned int id;
    char name[100];
    double est_dia_min;
    double est_dia_max;
    double relative_velocity;
    double miss_distance;
    char orbiting_body[100];
    char sentry_object[10];
    double absolute_mangitude;
    char hazardous[10];

};

