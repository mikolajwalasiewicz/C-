class Prostokat
{
public:
    Prostokat();
    Prostokat(float,float);
    float Pole_P();
    float Obwod_P();
    float Bok_a(float);
    float Bok_b(float);
    void wyswietl();
protected:
    float bok1;
    float bok2;

};
class Kwadrat : public Prostokat
{
public:
    Kwadrat();
    Kwadrat(float);
    float Bok_a(float);
    float Bok_b(float);

//protected:
    //float bok1;
};
