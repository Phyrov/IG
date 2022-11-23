class Vertice
{
    public:
        float x, y, z;

        // Constructores
        Vertice()
        {
            x = 0;
            y = 0;
            z = 0;
        }

        Vertice(float x, float y, float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        void operator = (const Vertice & otro)
        {
            this->x = otro.x;
            this->y = otro.y;
            this->z = otro.z;
        }

        

    private:

};
