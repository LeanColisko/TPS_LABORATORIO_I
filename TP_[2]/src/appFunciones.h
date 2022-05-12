/*
 * appFunciones.h
 *
 *  Created on: 27 abr. 2022
 *      Author: lcolisko
 */

#ifndef APPFUNCIONES_H_
#define APPFUNCIONES_H_

/// \fn MenuPrincipal()
/// \brief imprime por consola el menú principal de la aplicación
/// \return retorna un valor char con valores del '1' al '5'
char MenuPrincipal();

/// \brief imprime por consola el subMenu de modificacion de la aplicación
/// \param void solo imprime por pantalla cuando es invocada
/// \return retorna un valor char con valores del '1' al '6'
char SubMenuModificar();

/// \param void solo imprime por pantalla cuando es invocada
/// \brief imprime por consola el subMenu de informes de la aplicación
/// \return retorna un valor char con valores del '1' al '4'
char SubMenuInformar();

#endif /* APPFUNCIONES_H_ */
