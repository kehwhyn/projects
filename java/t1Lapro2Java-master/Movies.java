import java.util.Vector;

class Movies {

    private String name;
    private int year;
    private Directors director;
    private Vector< Actors > cast;

    public Movies() {}

    public void setName(String name) {

        this.name = name;
    }

    public void setYear(int year) {

        this.year = year;
    }

    public String getName() {

        return name;
    }

    public int getYear() {

        return year;
    }

    public void switchDirector(Directors dir) {

        this.director = dir;

    }

    public void switchActors(Actors act) {

        if (isInCast(act)) cast.remove(act); 
        
        else cast.add(act);
    }

    public Directors getDirector() {

        return director;
    }

    public Vector< Actors > getActors() {

        return cast;
    }

    public int getCastSize() {

        return cast.size();
    }

    public boolean isInCast(Actors act) {

        return (cast.contains(act)) ? true : false;
    }

    public boolean isInDirection(Directors dir) {

        return (dir.getName() == this.director.getName()) ? true : false;
    }

    public String toString() {

        return String.format("%d, %s", year, name);
    }
}
