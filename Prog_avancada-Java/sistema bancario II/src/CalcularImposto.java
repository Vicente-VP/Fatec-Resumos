import java.util.ArrayList;
import java.util.List;

public class CalcularImposto{
    private List<Double> valores = new ArrayList<>();
    private double totalImposto;

    public double getTotalImposto() {
        return totalImposto;
    }

    public void CalculaImposto(Tributavel tributo){
        valores.add(tributo.getValorImposto());
        totalImposto += tributo.getValorImposto();
    }
}
