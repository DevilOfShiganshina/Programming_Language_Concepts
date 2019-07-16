public class Complex {
  public Complex(double norm, double imag) {
    this.norm = norm;
    this.imag = imag;
  }

  public double get_norm() {
    return norm;
  }

  public double get_imag() {
    return imag;
  }

  public Complex Add(Complex x) {
    return new Complex(this.norm + x.norm, this.imag + x.imag);
  }

  public Complex Sub(Complex x) {
    return new Complex(this.norm - x.norm, this.imag - x.imag);
  }

  public Complex Mul(Complex x) {
    double norm = this.norm * x.norm - this.imag * x.imag;
    double imag = this.norm * x.norm + this.imag * x.imag;
    return new Complex(norm, imag);
  }

  public Complex Div(Complex x) {
    Complex res = this.Mul(new Complex(x.norm, -x.imag));
    double abs = x.norm * x.norm + x.imag * x.imag;
    return new Complex(res.norm / abs, res.imag / abs);
  }

  public Complex add(double x) {
    return this.Add(new Complex(x, 0));
  }

  public Complex sub(double x) {
    return this.Sub(new Complex(x, 0));
  }

  public Complex mul(double x) {
    return this.Mul(new Complex(x, 0));
  }

  public Complex div(double x) {
    return this.Div(new Complex(x, 0));
  }

  @Override
  public String toString() {
    Complex x = this;
    if (x.norm == 0 && x.imag == 0) {
      return "0";
    } else if (x.norm == 0) {
      return "" + x.imag + "i";
    } else if (x.imag == 0) {
      return "" + x.norm;
    } else if (x.imag > 0) {
      if (x.imag == 1) {
        return "" + x.norm + " +i";
      } else {
        return "" + x.norm + " + " + x.imag + "i";
      }
    } else {
      if (x.imag == -1) {
        return "" + x.norm + "-i";
      } else {
        return "" + x.norm + x.imag + "i";
      }
    }
  }

  private final double norm;
  private final double imag;

  public static void main(String[] args) {
    Complex x = new Complex(1, 2);
    Complex y = new Complex(3, 4);

    System.out.println(x + " + " + y + " = " + x.Add(y));
    System.out.println(x + " - " + y + " = " + x.Sub(y));
    System.out.println(x + " * " + y + " = " + x.Mul(y));
    System.out.println(x + " / " + y + " = " + x.Div(y));
    System.out.println();
    System.out.println(x + " + " + 5 + " = " + x.add(5));
    System.out.println(x + " - " + 5 + " = " + x.sub(5));
    System.out.println(x + " * " + 5 + " = " + x.mul(5));
    System.out.println(x + " / " + 5 + " = " + x.div(5));
  }
}