class Warrior
{
  public:
    virtual void info() = 0;       
    virtual ~Warrior() {}
};
  
class Infantryman: public Warrior
{
  public:
      void info() { cout << "Infantryman" << endl; }     
};
  
class Archer: public Warrior
{
  public:
    void info() { cout << "Archer" << endl; }     
};
  
class Horseman: public Warrior
{
  public:    
    void info() { cout << "Horseman" << endl; }     
};

enum Warrior_ID 
{ 
  Infantryman_ID=0,
  Archer_ID, 
  Horseman_ID 
};

Warrior * CreateWarrior( Warrior_ID id  )
{
    Warrior * p;
    switch (id)
    {
        case Infantryman_ID:
            p = new Infantryman;           
            break;      
        case Archer_ID:
            p = new Archer;           
            break;
        case Horseman_ID:
            p = new Horseman;           
            break;              
        default:
            p = nullptr;
    }
    return p;
}

int main ()
{
  auto* infan = CreateWarrior(Infantryman_ID);
  infan->info();
  auto archer = CreateWarrior(Archer_ID);
  archer->info();
  auto horseman = CreateWarrior(Horseman_ID);
  horseman->info();
  
  delete infan;
  delete archer;
  delete horseman;
};
