//
// Created by JoachimWagner on 08.04.2024.
//

#pragma once


class Schwein {
    int gewicht;
    void setGewicht(int gewicht) {
        this->gewicht = gewicht;
    }
public:
    int getGewicht() const {
        return gewicht;
    }

    void fuettern() {
        setGewicht(getGewicht() + 1);
    }

};
