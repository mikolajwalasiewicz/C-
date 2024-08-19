class Bryla
{
public:
    Bryla();
    Bryla(float,float,float);
    ~Bryla();
    float Pole();
    float Objetosc();
    void wyswietl();
protected:
    float bok1;
    float bok2;
    float bok3;
};
class Prostopaloscian : public Bryla
{
public:
    float zmien_bok();
    void wyswietl();
};
class Kula : public Bryla
{
public:
    void wyswietl();
    float Pole();
    float Objetosc();
    float zmien_bok();
};

