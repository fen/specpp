#ifndef BASE_CONTEXT_OBSERVER_HPP
#define BASE_CONTEXT_OBSERVER_HPP

namespace spec
{
    struct base_context_observer
    {
        std::vector<base_specify*> specifyers_m;
        std::string name;

        base_context_observer(std::string const& name)
        : name(name){}
        void register_self(base_specify* ptr)
        {
            specifyers_m.push_back( ptr );
        }
    };
}

#endif // BASE_CONTEXT_OBSERVER_HPP
