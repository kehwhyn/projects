import java.util.Vector;
import java.util.Scanner;

/*
 * preencher os vetores
 * implementar ultimo metodo
 * tem que mudar nome das funcoes que ficou mto ambiguo
 */
class menu {

    private Vector< Directors > directorsVector;
    private Vector< Actors >    actorsVector;
    private Vector< Movies >    moviesVector;
    private Scanner input = new Scanner(System.in);

    public menu() {

    }

    public void Menu() {

        boolean cond;

        do {
        
            System.out.println("Bem vindo!");
            System.out.println("Digite o numero da opcao para continuar");
            System.out.println("1 - Consultar Atores");
            System.out.println("2 - Consultar Diretores");
            System.out.println("3 - Consultar Filmes");
            System.out.println("4 - Cadastrar Filme");
            System.out.println("5 - Sair");
        
            cond = options(readFromUser());

        } while(cond);

    }

    public boolean options(String option) {

        boolean condition;

        switch (option) {

            case "1":
            
                consultarAtor();
                condition = true;

            break;
            
            case "2":
            
                consultarDiretor();
                condition = true;
            
            break;

            case "3":
                
                consultarFilme();
                condition = true;
            
            break;

            case "4":
            
                cadastrarNovoFilme();
                condition = true;
            
            break;

            case "5":
            
                cadastrarNovoFilme();
                condition = false;
            
            break;
        
            default:

                System.out.println("Opção não cadastrada, tente novamente.");
                condition = true;

            break;
        }

        return condition;
    }

    private String readFromUser() {

        return this.input.nextLine();

    }

    private < T > boolean inVectors(Vector< T > vector, T object) {

        return (vector.contains(object)) ? true : false;
    }

    private < T > void showContentsOf(Vector< T > vector) {

        System.out.println("Vou mostrar-lhe todos que podes consultar.");
        
        for (T aux : vector) aux.toString();
        
        System.out.println("");
    }

    private Actors getActor(String name) {

        Actors temporaryActor = new Actors();        

        temporaryActor.setName(name);

        return temporaryActor;
    }

    private Directors getDirector(String name) {
        
        Directors temporaryDirector = new Directors();

        temporaryDirector.setName(name);

        return temporaryDirector;
    }

    private Movies getMovie(String name) {

        Movies movie = new Movies();

        movie.setName(name);

        return movie;
    }

    private void showMoviesThatActorIsIn(Actors actor) {

        for(Movies movie : moviesVector)

                if(movie.isInCast(actor)) System.out.println(movie.toString());
    }

    private void showMoviesThatDirectorIs(Directors director) {

        for(Movies movie : moviesVector)
                          
                if(movie.isInDirection(director)) System.out.println(movie.toString());
    }

    private void showActor(Actors actor) {
        
        if(inVectors(this.actorsVector, actor)) {

            System.out.println(actor.getName());
            System.out.printf("Ano     Filme");

            showMoviesThatActorIsIn(actor);

        } else 

            System.out.println("O nome informado não existe");

    }

    private void showDirector(Directors director) {
        
        if(inVectors(this.directorsVector, director)) {

            System.out.println(director.getName());
            System.out.printf("Ano     Filme");

            showMoviesThatDirectorIs(director);

        } else 

            System.out.println("O nome informado não existe");

    }

    private void showMovie(Movies movie) {

        int index =  moviesVector.indexOf(movie);

        if(inVectors(this.moviesVector, movie)) {

            movie = moviesVector.get(index);
            System.out.printf("Filme: %s (%d)\n", movie.getName(), movie.getYear());
            System.out.printf("Diretor: %s\n", movie.getDirector().getName());
            System.out.println("Atores:");

            showContentsOf(movie.getActors());
            
        } else 

            System.out.println("O nome informado não existe");

    }

    public void consultarAtor() {

        showContentsOf(this.actorsVector);

        System.out.println("Agora, qual desejas consultar?");

        showActor(getActor(readFromUser()));
    }

    public void consultarDiretor() {

        showContentsOf(this.directorsVector);

        System.out.println("Agora, qual desejas consultar?");

        showDirector(getDirector(readFromUser()));
    }

    public void consultarFilme() {

        showContentsOf(this.moviesVector);

        System.out.println("Agora, qual desejas consultar?");

        showMovie(getMovie(readFromUser()));
    }

    public void cadastrarNovoFilme () {

    }
}
