#ifndef GATE_H
#define GATE_H

class Gate
{
    int gateId;
    public:

        Gate(int theGateId): gateId(theGateId) {}

        void setId(int id)
        {
            this->gateId = id;
        }

        int getGateId()
        {
            return this->gateId;
        }
};

#endif