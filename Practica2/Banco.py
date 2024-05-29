#Cesar Alejandro Velazquez Mercado
#372329

class Persona:
    def __init__(self, nombre, apellido, dni):
        self.__nombre = nombre
        self.__apellido = apellido
        self.__dni = dni

    def get_nombre(self):
        return self.__nombre

    def get_apellido(self):
        return self.__apellido

    def get_dni(self):
        return self.__dni

    def __str__(self):
        return f"{self.__nombre} {self.__apellido} - clave: {self.__dni}"

class Cliente(Persona):
    def __init__(self, nombre, apellido, dni, saldo_inicial):
        super().__init__(nombre, apellido, dni)
        self.__cuentas = [CuentaBancaria(saldo_inicial)]

    def agregar_cuenta(self, saldo_inicial):
        self.__cuentas.append(CuentaBancaria(saldo_inicial))

    def get_cuentas(self):
        return self.__cuentas

class CuentaBancaria:
    def __init__(self, saldo):
        self.__saldo = saldo

    def depositar(self, cantidad):
        self.__saldo += cantidad
        print("Depósito realizado.")

    def retirar(self, cantidad):
        if cantidad <= self.__saldo:
            self.__saldo -= cantidad
            print("Retiro realizado.")
            return True
        else:
            print("Saldo insuficiente.")
            return False

    def transferir(self, cantidad, cuenta_destino):
        if self.retirar(cantidad):
            cuenta_destino.depositar(cantidad)
            print("Transferencia realizada.")
        else:
            print("No se pudo realizar la transferencia.")

    def mostrar_saldo(self):
        print(f"Saldo actual: {self.__saldo}")

class Banco:
    def __init__(self):
        self.__clientes = {}

    def registrar_cliente(self, cliente):
        if cliente.get_dni() in self.__clientes:
            print("El cliente ya está registrado.")
        else:
            self.__clientes[cliente.get_dni()] = cliente
            print("Cliente registrado con éxito.")

    def iniciar_sesion(self, dni):
        if dni in self.__clientes:
            return self.__clientes[dni]
        else:
            print("Cliente no registrado.")
            return None

def menu_opciones(cliente):
    while True:
        print("\n--- Menú de opciones ---")
        print("1) Depositar")
        print("2) Mostrar saldo")
        print("3) Retirar")
        print("4) Transferir")
        print("5) Salir")
        opcion = input("Seleccione una opción: ")

        cuentas = cliente.get_cuentas()
        if opcion == "1":
            cantidad = float(input("Ingrese la cantidad a depositar: "))
            cuentas[0].depositar(cantidad)
        elif opcion == "2":
            cuentas[0].mostrar_saldo()
        elif opcion == "3":
            cantidad = float(input("Ingrese la cantidad a retirar: "))
            cuentas[0].retirar(cantidad)
        elif opcion == "4":
            dni_destino = input("Ingrese la clave del destinatario: ")
            if dni_destino in banco._Banco__clientes:
                cantidad = float(input("Ingrese la cantidad a transferir: "))
                cuenta_destino = banco._Banco__clientes[dni_destino].get_cuentas()[0]
                cuentas[0].transferir(cantidad, cuenta_destino)
            else:
                print("Cliente destinatario no encontrado.")
        elif opcion == "5":
            print("Saliendo del sistema.")
            break
        else:
            print("Opción inválida. Por favor, seleccione una opción válida.")

def registrar_cliente():
    nombre = input("Ingrese su nombre: ")
    apellido = input("Ingrese su apellido: ")
    dni = input("Ingrese su clave: ")
    saldo_inicial = float(input("Ingrese su saldo inicial: "))
    nuevo_cliente = Cliente(nombre, apellido, dni, saldo_inicial)
    banco.registrar_cliente(nuevo_cliente)

def menu_inicio():
    while True:
        print("\n--- Menú de Inicio ---")
        print("1) Iniciar sesión")
        print("2) Registrar usuario")
        print("3) Salir")
        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            dni = input("Ingrese su clave para iniciar sesión: ")
            cliente_actual = banco.iniciar_sesion(dni)
            if cliente_actual:
                print(f"Bienvenido, {cliente_actual.get_nombre()} {cliente_actual.get_apellido()}!")
                menu_opciones(cliente_actual)
        elif opcion == "2":
            registrar_cliente()
        elif opcion == "3":
            print("Saliendo del sistema.")
            break
        else:
            print("Opción inválida. Por favor, seleccione una opción válida.")

banco = Banco()

clientes = [
    Cliente("Juan", "Perez", "1234", 1000), #ejemplos 
    Cliente("Maria", "Gomez", "5678", 500)
]

for cliente in clientes:
    banco.registrar_cliente(cliente)

menu_inicio()
