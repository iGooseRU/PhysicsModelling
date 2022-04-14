#include <iostream>
#include <cmath>

class Rocket{
private:
    const long double m_earth_ = 5.972e24;
    const double r_earth_ = 6371000;
    const double G_ = 6.67e-14;

    double m_rocket_ = 30000, m_fuel_ = 40000, u_ = 250, v_fuel_= 800, alpha_ = 80;
    const double m_start_ = m_rocket_ + m_fuel_;
    double x_, y_ = 1, sec_ = 1;
    long double g_;
    double Vx_, Vy_;

public:
    static void show_data (){
        std::cout << "Ladies and gentlemen, our SpaceX Falcon Heavy rocket is ready for launching!" << std::endl;
        std::cout <<       "Weight of rocket (m_rocket): 30000 kg;" << std::endl;
        std::cout <<       "Weight of fuel (m_fuel): 40000 kg;" << std::endl;
        std::cout <<       "Speed of loosing gases (u): 250 kg per sec;" << std::endl;
        std::cout <<       "Speed of loosing fuel(v_fuel): 800 kg per sec;" << std::endl;
        std::cout <<       "Degree of launch (alpha, degrees): 80 degrees;" << std::endl;
        std::cout << "====================================================================================\n";
    }
    void flight(){
        while (y_ >= 0){
            g_ = G_ * (m_earth_ * sec_) / pow(r_earth_ + y_, 2);
            if (m_fuel_ > 0)
                Vx_ = u_ * log(m_start_ / (m_start_ - m_fuel_)) * cos(alpha_ * M_PI /
                                                                      180);
            Vy_ = u_ * log(m_start_ / (m_start_ - m_fuel_)) * sin(alpha_ * M_PI / 180)
                  - g_;
            m_fuel_ -= v_fuel_;
            x_ += Vx_;
            y_ += Vy_;
            if (y_ > 0){
                std::cout << "Time: " << sec_ << " sec."
                                                  " || x: " << x_ <<
                          " || y: " << y_ <<
                          " || Vx: " << Vx_ <<
                          " || Vy: " << Vy_ <<
                          "||v: " << sqrt(pow(Vx_, 2) + pow(Vy_, 2)) <<
                          " m/sec || m fuel: ";
                if (m_fuel_ > 0)
                    std::cout << m_fuel_ << " tons;\n";
                else
                    std::cout << "Tanks are empty!\n";
            }
            ++sec_;
        }
    }
};
int main()
{
    Rocket rocket;
    Rocket::show_data();
    rocket.flight();
    return 0;
}