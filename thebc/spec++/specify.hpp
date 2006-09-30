#ifndef SPECIFY_HPP
#define SPECIFY_HPP

#define specify( TEXT )\
struct JOIN(specify_, __LINE__) : spec::base_specify, data \
{\
    JOIN(specify_, __LINE__)() : spec::base_specify(TEXT, __FILE__, __LINE__), data()\
    {\
        observer.register_self(this);\
    }\
    void specify_method();\
};\
JOIN(specify_, __LINE__) JOIN(specify_obj_, __LINE__);\
void JOIN(specify_, __LINE__)::specify_method()

#endif // SPECIFY_HPP
