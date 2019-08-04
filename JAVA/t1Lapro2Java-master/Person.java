abstract class Person {

    private String name;

    public Person() {

        name = null;
    }

    public void setName(String name) {

        this.name = name;
    }

    public String getName() {

        return name;
    }

    public String toString(){

        return String.format("%s", getName());
    }
}