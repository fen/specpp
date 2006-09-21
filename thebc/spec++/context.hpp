#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#define context( TEXT, FIXTURE ) \
    namespace FIXTURE##_namespace{\
        template<typename FIXTURE>\
        struct abstract : FIXTURE\
        {\
            template<int n>\
            void specify_func()\
            {\
                dummy_m = true;\
            }\
            template<int n>\
            void register_info()\
            {\
            }\
            bool dummy_m;\
            std::map<int, std::string> specify_text;\
            std::map<int, int> specify_line;\
            std::map<int, std::string> specify_file;\
        };\
        typedef spec::context_handler<FIXTURE##_namespace::abstract<FIXTURE> > data;\
        data object(TEXT);\
    }\
    namespace FIXTURE##_namespace

/* REVISIT (fred) : The registration of TEXT __LINE__ __FILE__ has to be done better.*/
/* REVISIT (fred) : It would be nice if IDENTIFIER could be removed and have sort of auto incremented macros or template */
#define specify( TEXT, IDENTIFIER ) \
    template<>\
    template<>\
    void data::context::register_info<IDENTIFIER>()\
    {\
        specify_text[IDENTIFIER] = TEXT;\
        specify_line[IDENTIFIER] = __LINE__;\
        specify_file[IDENTIFIER] = __FILE__;\
    }\
    template<>\
    template<>\
    void data::context::specify_func<IDENTIFIER>()\


#endif // CONTEXT_HPP
