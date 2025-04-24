import java.util.ArrayList;

public class EquipeDeProjeto {
    private ArrayList<Empregado> participantes;

    public EquipeDeProjeto(Empregado p) {
        this.participantes = new ArrayList<Empregado>();
        this.participantes.add(p);
    }

    public EquipeDeProjeto(ArrayList<Empregado> participantes) {
        if (participantes.size() > 0)
            this.participantes = new ArrayList<Empregado>(participantes);
        else
            this.participantes = new ArrayList<Empregado>();
    }

    public void adicionaParticipante(Empregado p) {
        this.participantes.add(p);
    }
}