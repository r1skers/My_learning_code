#ifndef ANIMAL_BASE_H
#define ANIMAL_BASE_H

class animal_base
{
    private:
        int height;
    public:
        animal_base();
        animal_base(int h);
        virtual ~animal_base(){};
        virtual void talk() = 0;
};

#endif