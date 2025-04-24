import java.util.ArrayList;

public class Empresa {
    private ArrayList<Empregado> empregados;
    private ArrayList<EquipeDeProjeto> equipes;
    
    public Empresa(ArrayList<Empregado> empregados, ArrayList<EquipeDeProjeto> equipes) {
        this.empregados = new ArrayList<Empregado>(empregados);
        this.equipes = new ArrayList<EquipeDeProjeto>(equipes);
    }

    public Empresa(Empregado e, EquipeDeProjeto eqp) {
        this.empregados = new ArrayList<Empregado>();
        this.equipes = new ArrayList<EquipeDeProjeto>();

        this.empregados.add(e);
        this.equipes.add(eqp);
    }

    public void adicionaEmpregado(Empregado e) {
        this.empregados.add(e);
    }
    public void adicionaEquipe(EquipeDeProjeto eqp) {
        this.equipes.add(eqp);
    }
}