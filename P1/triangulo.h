
class Triangulo
{
    public:
        int a, b, c;

        // Constructores
        Triangulo()
        {

        }
        Triangulo(int a, int b, int c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        void operator = (const Triangulo & otro)
        {
            this->a = otro.a;
            this->b = otro.b;
            this->c = otro.c;
        }

    private:

};