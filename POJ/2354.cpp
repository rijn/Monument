/*
 * CS 491
 * problem set #1
 * poj 2354
 *
 * Aug 30, 2016
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

double calculate_dist(double l1, double d1, double l2, double d2) {

    double r = 6875.0 / 2; //Earth radius
    double p = acos(-1.0);

    l1 *= p / 180;
    d1 *= p / 180;
    l2 *= p / 180;
    d2 *= p / 180;

    return r * acos(cos(l1) * cos(l2) * cos(d1-d2) + sin(l1) * sin(l2));
}

double read_coordinate() {

    double d, m, s;
    char temp[20];

    scanf("%lf^%lf'%lf\" %s", &d, &m, &s, temp);
    double length = d + m / 60 + s / 3600;
    if(temp[0] == 'S' || temp[0] == 'W') {
       length *= -1;
    }

    return length;
}

void flush_buffer(int count) {
    char temp[100];
    while(count--) {
        scanf("%s", temp);
    }
    return;
}

int main() {

    double l1, l2, d1, d2, dis;

    flush_buffer(9);

    l1 = read_coordinate();

    flush_buffer(1);

    d1 = read_coordinate();

    flush_buffer(5);

    l2 = read_coordinate();

    flush_buffer(1);

    d2 = read_coordinate();

    flush_buffer(1);

    dis = calculate_dist(l1,d1,l2,d2);

    printf("The distance to the iceberg: %.2lf miles.\n", dis);

    if(floor(dis + 0.005) < 100) {
        printf("DANGER!\n");
    }

    return 0;
}

