#pragma once

class credit;

bool cmp_value(const credit& k1, const credit& k2);
bool cmp_value_info(const credit& k1, const credit& k2);

void write(credit** cr, int n, const char* description);
void sort(/* uzupelnij parametry */);



