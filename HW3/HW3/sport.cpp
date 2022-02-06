
class Sport {
public:
    Sport(string sportName) {}
    virtual ~Sport() {}
    virtual const string name() const = 0;
    virtual const string icon() const = 0;
    virtual const bool isOutdoor() const = 0;
};

class Biathlon: public Sport {
public:
    Biathlon(string name, double distance):Sport(name)
    {
        m_name = name;
        m_distance = distance;
    }
    ~Biathlon() {
        cout << "Destroying the Biathlon object named " << m_name << ", distance " << m_distance << " km." << endl;
    }
    virtual const string name() const {return m_name;}
    virtual const string icon() const {return "a skier with a rifle";}
    virtual const bool isOutdoor() const {return true;}
    
private:
    string m_name;
    double m_distance;
};

class Snowboarding: public Sport {
public:
    Snowboarding(string name):Sport(name)
    {
        m_name = name;
    }
    ~Snowboarding() {
        cout << "Destroying the Snowboarding object named " << m_name << "." << endl;
    }
    virtual const string name() const {return m_name;}
    virtual const string icon() const {return "a descending snowboarder";}
    virtual const bool isOutdoor() const {return true;}
    
private:
    string m_name;
};

class FigureSkating: public Sport {
public:
    FigureSkating(string name):Sport(name)
    {
        m_name = name;
    }
    ~FigureSkating() {
        cout << "Destroying the FigureSkating object named " << m_name << "." << endl;
    }
    virtual const string name() const {return m_name;}
    virtual const string icon() const {return "a skater in the Biellmann position";}
    virtual const bool isOutdoor() const {return false;}
    
private:
    string m_name;
};
