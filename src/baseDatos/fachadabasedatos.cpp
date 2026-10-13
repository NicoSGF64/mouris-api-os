#include "fachadabasedatos.h"

FachadaBaseDatos::FachadaBaseDatos(const std::string& dsn, const Usuario &u) : dsnBBDD(dsn)
{
    // Transformar en minúsculas debido a que postgres só permite minúsculas nos nomes de usuario
    std::string nomeMinusculas = u.getNomeUsuario().value_or("consulta");
    std::transform(nomeMinusculas.begin(), nomeMinusculas.end(), nomeMinusculas.begin(),[](unsigned char c){ return std::tolower(c);});

    // Por motivos fora do meu coñecemento, nanodbc::conection(dns, user, password) non funciona así que hai que facer esta chapuza
    dsnBBDD += ";Uid=" + nomeMinusculas + ";";
    dsnBBDD += "Pwd=" + u.getContrasinal().value_or("consulta") + ";";

    con = nanodbc::connection(dsnBBDD);
}