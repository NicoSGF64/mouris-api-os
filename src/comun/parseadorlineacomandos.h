#ifndef PARSEADORLINEACOMANDOS_H
#define PARSEADORLINEACOMANDOS_H
#include <optional>
#include <stdexcept>
#include <string>

struct OpcionsPrograma
{
    std::string rutaCertificado;
    std::string rutaChave;
    std::string datosDSN;
    std::optional<unsigned int> porto;
    static constexpr unsigned short numeroParametrosEsenciais = 3;
};

class ErroSenParametroEsencial : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

class ParseadorLineaComandos
{
public:
    ParseadorLineaComandos() = default;
    OpcionsPrograma obterOpcions(int argc, char *argv[]);
private:
    constexpr std::string configurarOpcion(char *lineacomandos[], int& posicion);
    unsigned int configurarValor(char *lineacomandos[], int& posicion);
};

#endif // PARSEADORLINEACOMANDOS_H
