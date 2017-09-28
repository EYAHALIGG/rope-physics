#pragma once

#define gentypes(name) \
typedef name<int> name##i; \
typedef name<float> name##f; \
typedef name<double> name##d;