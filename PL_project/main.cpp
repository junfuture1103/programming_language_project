#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 2048

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"MoveObject.h"
#include"ObserveObject.h"
#include"StarObject.h"
#include"MovingStar.h"

// Orb 정보를 담을 구조체 구현
typedef struct _input_col_t {
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
} input_col_t;

void my_print(input_col_t tmp);
void my_scan_line(const char* tmp_line, input_col_t* tmp);

int preprocess_data(input_col_t* input_list, int* len);

int preprocess_data(input_col_t* input_list, int* len) {
    const char* fname = "neo_small.csv";
    FILE* fp;

    fp = fopen(fname, "r");

    if (fp == NULL) {
        printf("fail to open file");
        return -1;
    }

    char* tmp_line;
    char line[MAX_LENGTH];

    //process first line
    tmp_line = fgets(line, MAX_LENGTH, fp);
    printf("%s", tmp_line);

    while (!feof(fp)) {
        input_col_t tmp;
        tmp_line = fgets(line, MAX_LENGTH, fp);
        if (tmp_line != NULL) {
            my_scan_line(tmp_line, &tmp);
            my_print(tmp);
        }
    }

    // complete data input
    printf("Stored all elements\n");
    fclose(fp);

}

void my_print(input_col_t tmp) {
    printf("%d %s %lf %lf %lf %lf %s %s %lf %s",
        tmp.id,
        tmp.name,
        tmp.est_dia_min,
        tmp.est_dia_max,
        tmp.relative_velocity,
        tmp.miss_distance,
        tmp.orbiting_body,
        tmp.sentry_object,
        tmp.absolute_mangitude,
        tmp.hazardous);
    return;
}

void my_scan_line(const char* tmp_line, input_col_t* tmp) {
    sscanf(tmp_line, "%d,%[^,],%lf,%lf,%lf,%lf,%[^,],%[^,],%lf,%[^,]\n",
        &tmp->id,
        tmp->name,
        &tmp->est_dia_min,
        &tmp->est_dia_max,
        &tmp->relative_velocity,
        &tmp->miss_distance,
        tmp->orbiting_body,
        tmp->sentry_object,
        &tmp->absolute_mangitude,
        tmp->hazardous
    );
    return;
}

void make_class(input_col_t* list, int len) {
    for (int i = 0; i < len; i++) {
        MoveObject tmp_mo(list[i].est_dia_min, list[i].est_dia_max);
        ObserveObject tmp_oo(list[i].relative_velocity, list[i].miss_distance);
        StarObject tmp_so(list[i].absolute_mangitude);

        MovingStar tmp_MS(*tmp_so.absolute_magnitude, tmp_mo.est_diameter_max);

        tmp_mo.set_name(list[i].name);
        tmp_mo.add_id();
        tmp_mo.get_value();

        tmp_oo.set_name(list[i].name);
        tmp_oo.add_id();
        tmp_oo.get_value();

        tmp_so.set_name(list[i].name);
        tmp_so.add_id();
        tmp_so.get_value();

        printf("twinkle : %lf\n", tmp_MS.cal_twinkle());
    }

}

int main(int argc, char** argv) {
    const char* fname = "neo_small.csv";
    FILE* fp;
    input_col_t* input_list = (input_col_t*)malloc(sizeof(input_col_t));
    int len = 0;

    fp = fopen(fname, "r");

    if (fp == NULL) {
        printf("fail to open file");
        return -1;
    }

    char* tmp_line;
    char line[MAX_LENGTH];

    //process first line
    tmp_line = fgets(line, MAX_LENGTH, fp);
    printf("%s", tmp_line);

    while (!feof(fp)) {
        input_col_t tmp;
        tmp_line = fgets(line, MAX_LENGTH, fp);
        if (tmp_line != NULL) {
            my_scan_line(tmp_line, &tmp);
            my_print(tmp);

            //input to dynamic array
            if (len != 0) {
               input_list = (input_col_t*)realloc(input_list, sizeof(input_col_t) * (len + 1));
            }

            input_list[len] = tmp;
            len++;
        }
    }

    // complete data input
    printf("Stored all elements\n");
    fclose(fp);

    for (int i = 0; i < len; i++) {
        my_print(input_list[i]);
    }

    make_class(input_list, len);

    return 0;
}
